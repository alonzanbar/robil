FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../src/C21_VisionAndLidar/msg"
  "../src/C21_VisionAndLidar/srv"
  "../msg_gen"
  "../srv_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/C21_VisionAndLidar/msg/__init__.py"
  "../src/C21_VisionAndLidar/msg/_C21C0_3DR.py"
  "../src/C21_VisionAndLidar/msg/_C0C21_SIZ.py"
  "../src/C21_VisionAndLidar/msg/_C0C21_RES.py"
  "../src/C21_VisionAndLidar/msg/_C0C21_LAZ.py"
  "../src/C21_VisionAndLidar/msg/_C21C0_3DF.py"
  "../src/C21_VisionAndLidar/msg/_C0C21_CAM.py"
  "../src/C21_VisionAndLidar/msg/_C0C21_AZI.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
