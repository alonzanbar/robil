/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package terminal;

import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;

import terminal.commands.Command;

public class Terminal extends javax.swing.JFrame {

	/**
	 * Creates new form Terminal
	 */
	public Terminal() {
		initComponents();

		ProgramRegistrator.register(this);
		print(getPromt());
		
		txtIn.requestFocus();

	}

	/**
	 * This method is called from within the constructor to initialize the form.
	 * WARNING: Do NOT modify this code. The content of this method is always
	 * regenerated by the Form Editor.
	 */
	@SuppressWarnings("unchecked")
	// <editor-fold defaultstate="collapsed"
	// desc="Generated Code">//GEN-BEGIN:initComponents
	private void initComponents() {

		txtIn = new javax.swing.JTextArea();
		jScrollPane1 = new javax.swing.JScrollPane();
		txtOut = new javax.swing.JTextArea();

		setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

		txtIn.setColumns(20);
		txtIn.setRows(5);
		txtIn.setFocusable(true);
		txtIn.addKeyListener(new java.awt.event.KeyAdapter() {
			public void keyTyped(java.awt.event.KeyEvent evt) {
				txtInKeyTyped(evt);
			}

			public void keyPressed(java.awt.event.KeyEvent evt) {
				txtInKeyPressed(evt);
			}

			public void keyReleased(java.awt.event.KeyEvent evt) {
				txtInKeyReleased(evt);
			}
		});

		txtOut.setEditable(false);
		txtOut.setColumns(20);
		txtOut.setRows(5);
		//txtOut.setFocusable(false);
		jScrollPane1.setViewportView(txtOut);

		javax.swing.GroupLayout layout = new javax.swing.GroupLayout(
				getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout
				.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addComponent(txtIn, javax.swing.GroupLayout.Alignment.TRAILING)
				.addComponent(jScrollPane1,
						javax.swing.GroupLayout.DEFAULT_SIZE, 808,
						Short.MAX_VALUE));
		layout.setVerticalGroup(layout
				.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
				.addGroup(
						layout.createSequentialGroup()
								.addComponent(jScrollPane1,
										javax.swing.GroupLayout.DEFAULT_SIZE,
										550, Short.MAX_VALUE)
								.addPreferredGap(
										javax.swing.LayoutStyle.ComponentPlacement.RELATED)
								.addComponent(txtIn,
										javax.swing.GroupLayout.PREFERRED_SIZE,
										34,
										javax.swing.GroupLayout.PREFERRED_SIZE)));

		pack();
	}// </editor-fold>//GEN-END:initComponents

	public ArrayList<String> history = new ArrayList<String>();
	public int history_index = 0;
	public String input = "";
	static public ArrayList<Command> commands = new ArrayList<Command>();
	ReentrantLock consoleLock = new ReentrantLock();
	Command activeProgram = null;

	public String getPromt() {
		return "Executer$ ";
	}

	static public Command registerProgram(Command prog) {
		commands.add(prog);
		return prog;
	}

	private void runCommand(String input) {
		if (activeProgram != null) {
			return;
		}

		boolean found = false;
		for (Command cmd : commands) {
			if (cmd.isRelatedTo(input)) {
				consoleLock.lock();
				try {
					activeProgram = cmd;
				} finally {
					consoleLock.unlock();
				}
				cmd.thread = new Thread() {
					Command p;
					String input;

					public Thread init(Command p, String input) {
						this.p = p;
						this.input = input;
						return this;
					}

					public void run() {
						p.execute(input.trim());
						consoleLock.lock();
						try {
							activeProgram = null;
						} finally {
							consoleLock.unlock();
						}
						print(getPromt());
					}
				}.init(cmd, input);
				cmd.thread.start();

				found = true;
			}
		}
		if (!found) {
			println("ERROR: command not found");
			print(getPromt());
		}
	}

	private void autocomplete(String input) {
		ArrayList<String> commandVariations = new ArrayList<String>();
		for (Command p : commands) {
			if (p.isAutoCompleteAvailable(input)) {
				commandVariations.addAll(p.autocomplete(input.trim()));
			}
		}
		if (commandVariations.size() == 0)
			return;
		if (commandVariations.size() > 50) {
			print("More then 50 variants...");
			print(getPromt());
			return;
		}
		if (commandVariations.size() == 1) {
			input = commandVariations.get(0);
			txtIn.setText(input);
			return;
		} else {
			String possibleCommand = "";
			for (int i = 0; i < commandVariations.get(0).length(); i++) {
				String prefixCommand = new String(possibleCommand);
				prefixCommand += commandVariations.get(0).substring(i, i + 1);
				boolean foundPrefix = false;
				for (String word : commandVariations) {
					if (word.startsWith(prefixCommand) == false) {
						foundPrefix = true;
						break;
					}
				}
				if (foundPrefix) {
					break;
				}
				
				possibleCommand = prefixCommand;
				
			}
			input = possibleCommand;
			txtIn.setText(input);
		}
		println();
		println("Variants:");
		for (String v : commandVariations) {
			println(v);
		}
		print(getPromt());
	}

	private void txtInKeyTyped(java.awt.event.KeyEvent evt) {// GEN-FIRST:event_txtInKeyTyped
		String in = txtIn.getText();
		if (evt.getKeyChar() == '\n') {
			String command = in.substring(0, in.length() - 1);
			input = command + '\n';
			print(input);
			txtIn.setText("");
			history.add(command);
			runCommand(command);
			input = "";
			evt.consume();
		}
	}// GEN-LAST:event_txtInKeyTyped

	private void txtInKeyPressed(java.awt.event.KeyEvent evt) {// GEN-FIRST:event_txtInKeyPressed
		if (evt.getKeyCode() == KeyEvent.VK_UP) {
			if (history.size() == 0)
				return;
			history_index++;
			if (history_index >= history.size())
				history_index = history.size();
			txtIn.setText(history.get(history.size() - history_index));
			evt.consume();
			return;
		}
		if (evt.getKeyCode() == KeyEvent.VK_DOWN) {
			history_index--;
			if (history_index < 0)
				history_index = 0;
			if (history_index > 0)
				txtIn.setText(history.get(history.size() - history_index));
			else
				txtIn.setText(input);
			evt.consume();
			return;
		}
		if (evt.getKeyCode() == KeyEvent.VK_TAB) {
			evt.consume();
			autocomplete(input);
			return;
		}
		if (evt.isControlDown() && evt.getKeyCode() == KeyEvent.VK_C) {
			println("^C");
			if (activeProgram != null) {
				activeProgram.stop();
				activeProgram = null;
				print(getPromt());
			}
			txtIn.setText("");
			return;
		}
		// println(""+evt.getExtendedKeyCode());
	}// GEN-LAST:event_txtInKeyPressed

	private void txtInKeyReleased(java.awt.event.KeyEvent evt) {// GEN-FIRST:event_txtInKeyReleased
		if (evt.getKeyCode() == KeyEvent.VK_UP)
			return;
		if (evt.getKeyCode() == KeyEvent.VK_DOWN)
			return;
		String in = txtIn.getText();
		input = in;
	}// GEN-LAST:event_txtInKeyReleased

	/**
	 * Writes text to GUI console
	 * 
	 * @param text
	 */
	public void print(String text) {
		consoleLock.lock();
		try {
			String out = txtOut.getText();
			//System.out.println("TERMINAL: " + out + text);
			txtOut.setText(out + text);
			txtOut.setCaretPosition(txtOut.getText().length() - 1);
		} finally {
			consoleLock.unlock();
		}
	}

	public void println(String text) {
		print(text + "\n");
	}

	public void println() {
		print("\n");
	}

	/**
	 * @param args
	 *            the command line arguments
	 */
	public static void main(String args[]) {
		/* Set the Nimbus look and feel */
		// <editor-fold defaultstate="collapsed"
		// desc=" Look and feel setting code (optional) ">
		/*
		 * If Nimbus (introduced in Java SE 6) is not available, stay with the
		 * default look and feel. For details see
		 * http://download.oracle.com/javase
		 * /tutorial/uiswing/lookandfeel/plaf.html
		 */
		try {
			for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager
					.getInstalledLookAndFeels()) {
				if ("Nimbus".equals(info.getName())) {
					javax.swing.UIManager.setLookAndFeel(info.getClassName());
					break;
				}
			}
		} catch (ClassNotFoundException ex) {
			java.util.logging.Logger.getLogger(Terminal.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		} catch (InstantiationException ex) {
			java.util.logging.Logger.getLogger(Terminal.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		} catch (IllegalAccessException ex) {
			java.util.logging.Logger.getLogger(Terminal.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		} catch (javax.swing.UnsupportedLookAndFeelException ex) {
			java.util.logging.Logger.getLogger(Terminal.class.getName()).log(
					java.util.logging.Level.SEVERE, null, ex);
		}
		// </editor-fold>

		/* Create and display the form */
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new Terminal().setVisible(true);
			}
		});
	}

	// Variables declaration - do not modify//GEN-BEGIN:variables
	private javax.swing.JScrollPane jScrollPane1;
	private javax.swing.JTextArea txtIn;
	private javax.swing.JTextArea txtOut;
	// End of variables declaration//GEN-END:variables
}