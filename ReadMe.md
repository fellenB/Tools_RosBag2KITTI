## About ##

In the current process of Intelligent Vehicle' data acquisition (LiDAR data and visual data), we usually complete the recording of data in the ROS system. Therefore, the data we directly get is saved in the .bag file format. However, the data format of most existing perception network frameworks is consistent with the data format of the KITTI dataset. In  KITTI dataset, image files are saved in .png format and PointCloud files are saved as .bin files. So we need to complete the conversion from the .bag file to the .png and .bin files.

## Steps ##

### 1. Decode .bag files ###
Data files recorded via ROS are usually saved in .bag format. We need to use the ROS system to decode the .bag file. The decoded files include image files(.png) and PointCloud files(.pcd).

* **Build the project**
	
	`cd catkin_ws`; `catkin_make`

* **Coordinate system transformation(Optional):**The purpose of coordinate system rotation and translation is achieved by adjusting the following parameter values in the file [map_generation_node.cpp](/catkin_ws/src/obstacle_detection/src/map_generation_node.cpp). All rotation parameters are angled and clockwise is positive.


* **Decoding:** Run `roscore` on the first console. Then open a new console, run `./devel/lib/obstacle_detection/map_generate`in the *catkin_ws* directory. Open a new console, run `rosbag play xxx.bag -r 0.1`. The result files are save into the [output](/catkin_ws/output).
> 0.1 in the code means 0.1 times speed. The Speed is determined according to computer io performance. Make sure the timestamps are within +-50ms, otherwise adjust the play speed. 


### 2. Pcb 2 Bin ###

The PointCloud files decoded from the .bag file are usually in .pcd format. In order to facilitate the experiment of 3D detection, the format of the KITTI data set needs to be unified, that is, converted into the .bin format. In the .bin file, each point corresponds to four data, which are xyz and intensity.





