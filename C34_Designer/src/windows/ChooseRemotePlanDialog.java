package windows;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.SwingConstants;

/*
 * ListDialog.java is meant to be used by programs such as
 * ListDialogRunner.  It requires no additional files.
 */

/**
 * Use this modal dialog to let the user choose one string from a long list. See
 * ListDialogRunner.java for an example of using ListDialog. The basics:
 * 
 * <pre>
 * String[] choices = { &quot;A&quot;, &quot;long&quot;, &quot;array&quot;, &quot;of&quot;, &quot;strings&quot; };
 * String selectedName = ListDialog.showDialog(componentInControllingFrame,
 * 		locatorComponent, &quot;A description of the list:&quot;, &quot;Dialog Title&quot;,
 * 		choices, choices[0]);
 * </pre>
 */
public class ChooseRemotePlanDialog extends JDialog implements ActionListener {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static ChooseRemotePlanDialog dialog;
	private static String value = "";

	/**
	 * Set up and show the dialog. The first Component argument determines which
	 * frame the dialog depends on; it should be a component in the dialog's
	 * controlling frame. The second Component argument should be null if you
	 * want the dialog to come up with its left corner in the center of the
	 * screen; otherwise, it should be the component on top of which the dialog
	 * should appear.
	 */
	public static String showDialog(Component frameComp,
			Component locationComp, String labelText, String title,
			String[] possibleValues, String initialValue, String longValue) {
		Frame frame = JOptionPane.getFrameForComponent(frameComp);

		dialog = new ChooseRemotePlanDialog(frame, locationComp, labelText,
				title, possibleValues, initialValue, longValue);

		dialog.setVisible(true);
		return value;
	}

	@SuppressWarnings("rawtypes")
	private JList list;

	@SuppressWarnings({ "unchecked", "rawtypes" })
	private ChooseRemotePlanDialog(Frame frame, Component locationComp,
			String labelText, String title, String[] data, String initialValue,
			String longValue) {
		super(frame, title, true);

		// Create and initialize the buttons.
		JButton cancelButton = new JButton("Cancel");
		cancelButton.addActionListener(this);
		//
		final JButton loadButton = new JButton("Load");
		loadButton.setActionCommand("Load");
		loadButton.addActionListener(this);
		getRootPane().setDefaultButton(loadButton);

		// main part of the dialog
		this.list = new JList(data) {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			// Subclass JList to workaround bug 4832765, which can cause the
			// scroll pane to not let the user easily scroll up to the beginning
			// of the list. An alternative would be to set the unitIncrement
			// of the JScrollBar to a fixed value. You wouldn't get the nice
			// aligned scrolling, but it should work.
			@Override
			public int getScrollableUnitIncrement(Rectangle visibleRect,
					int orientation, int direction) {
				int row;
				if (orientation == SwingConstants.VERTICAL && direction < 0
						&& (row = getFirstVisibleIndex()) != -1) {
					Rectangle r = getCellBounds(row, row);
					if ((r.y == visibleRect.y) && (row != 0)) {
						Point loc = r.getLocation();
						loc.y--;
						int prevIndex = locationToIndex(loc);
						Rectangle prevR = getCellBounds(prevIndex, prevIndex);

						if (prevR == null || prevR.y >= r.y) {
							return 0;
						}
						return prevR.height;
					}
				}
				return super.getScrollableUnitIncrement(visibleRect,
						orientation, direction);
			}
		};

		this.list
				.setSelectionMode(ListSelectionModel.SINGLE_INTERVAL_SELECTION);
		if (longValue != null) {
			this.list.setPrototypeCellValue(longValue); // get extra space
		}
		this.list.setLayoutOrientation(JList.HORIZONTAL_WRAP);
		this.list.setVisibleRowCount(-1);
		this.list.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if (e.getClickCount() == 2) {
					loadButton.doClick(); // emulate button click
				}
			}
		});
		// list.setSize(500, 2000);
		JScrollPane listScroller = new JScrollPane(this.list);
		listScroller.setPreferredSize(new Dimension(250, 80));
		listScroller.setAlignmentX(LEFT_ALIGNMENT);

		// Create a container so that we can add a title around
		// the scroll pane. Can't add a title directly to the
		// scroll pane because its background would be white.
		// Lay out the label and scroll pane from top to bottom.
		JPanel listPane = new JPanel();
		listPane.setLayout(new BoxLayout(listPane, BoxLayout.PAGE_AXIS));
		JLabel label = new JLabel(labelText);
		label.setLabelFor(this.list);
		listPane.add(label);
		listPane.add(Box.createRigidArea(new Dimension(0, 5)));
		listPane.add(listScroller);
		listPane.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

		// Lay out the buttons from left to right.
		JPanel buttonPane = new JPanel();
		buttonPane.setLayout(new BoxLayout(buttonPane, BoxLayout.LINE_AXIS));
		buttonPane.setBorder(BorderFactory.createEmptyBorder(0, 10, 10, 10));
		buttonPane.add(Box.createHorizontalGlue());
		buttonPane.add(cancelButton);
		buttonPane.add(Box.createRigidArea(new Dimension(10, 0)));
		buttonPane.add(loadButton);

		// Put everything together, using the content pane's BorderLayout.
		Container contentPane = getContentPane();
		contentPane.setSize(1000, 1000);
		listPane.setSize(1000, 1000);
		contentPane.add(listPane, BorderLayout.CENTER);
		contentPane.add(buttonPane, BorderLayout.PAGE_END);

		// Initialize values.
		setValue(initialValue);
		pack();
		setLocationRelativeTo(locationComp);
	}

	// Handle clicks on the Set and Cancel buttons.
	@Override
	public void actionPerformed(ActionEvent e) {
		if ("Load".equals(e.getActionCommand())) {
			ChooseRemotePlanDialog.value = (String) (this.list
					.getSelectedValue());
		}
		ChooseRemotePlanDialog.dialog.setVisible(false);
	}

	private void setValue(String newValue) {
		value = newValue;
		this.list.setSelectedValue(value, true);
	}
}