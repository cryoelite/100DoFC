import 'dart:async';

import 'package:flutter/material.dart';
import 'package:torch_compat/torch_compat.dart';

import 'package:augment_zero/Utility/Class_ScreenConf.dart';
import 'package:augment_zero/FirstRoute/Route_CameraView.dart';
import 'package:augment_zero/Utility/Class_OrientationObserver.dart';
import 'package:flutter/services.dart';

enum FLASHSTATUS {
  ON,
  OFF,
}

class RouteHome extends StatefulWidget {
  final ClassScreenConf getClass;

  RouteHome(BuildContext context, {Key key})
      : getClass = ClassScreenConf(context),
        super(key: key);
  @override
  _RouteHomeState createState() => _RouteHomeState();
}

class _RouteHomeState extends State<RouteHome> with ClassOrientationObserver {
  String shape = "Cube";
  String materialColor = "Red";
  StreamController<CAMSTATE> cameraButton = StreamController<CAMSTATE>();
  FLASHSTATUS flashstatus = FLASHSTATUS.OFF;
  List<DropdownMenuItem<dynamic>> menuItems = [];
  List<DropdownMenuItem<dynamic>> shapeItems = [];
  List<DropdownMenuItem<dynamic>> materialColorItems = [];
  _RouteHomeState() {
    setConstraints();
    menuItems = [
      DropdownMenuItem<DropdownButton>(
        child: DropdownButton<dynamic>(
          items: shapeItems,
          hint: Text("Shape"),
          onChanged: (value) {
            shape = value.toString();
          },
          value: shape,
        ),
        onTap: () {},
      ),
      DropdownMenuItem(
        child: Text("Color"),
        onTap: () {},
      ),
    ];

    shapeItems = [
      DropdownMenuItem(
        child: Text("Cube"),
        onTap: () {
          shape = "Cube";
        },
        value: shape,
      ),
      DropdownMenuItem(
        child: Text("Sphere"),
        onTap: () {
          shape = "Sphere";
        },
        value: shape,
      ),
      DropdownMenuItem(
        child: Text("Cylinder"),
        onTap: () {
          shape = "Cylinder";
        },
        value: shape,
      ),
    ];

    materialColorItems = [
      DropdownMenuItem(
        child: Text("Blue"),
        onTap: () {
          materialColor = "Blue";
        },
        value: materialColor,
      ),
    ];
    materialColorItems = [
      DropdownMenuItem(
        child: Text("Red"),
        onTap: () {
          materialColor = "Red";
        },
        value: materialColor,
      ),
    ];
    materialColorItems = [
      DropdownMenuItem(
        child: Text("Yellow"),
        onTap: () {
          materialColor = "Yellow";
        },
        value: materialColor,
      ),
    ];
    materialColorItems = [
      DropdownMenuItem(
        child: Text("Green"),
        onTap: () {
          materialColor = "Green";
        },
        value: materialColor,
      ),
    ];
  }

  @override
  void initState() {
    super.initState();
    startObserver();
  }

  @override
  void dispose() {
    cameraButton.close();
    stopObserver();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    SystemChrome.setPreferredOrientations([DeviceOrientation.portraitUp]);
    return Scaffold(
      backgroundColor: Colors.black,
      body: Container(
        width: maxWidth,
        height: maxHeight,
        child: Stack(
          children: [
            buildPortrait(),
            /* StreamBuilder<ORIENTATION>(
              stream: accelStreamClr.stream,
              builder: (context, AsyncSnapshot<ORIENTATION> snapshot) {
                setConstraints();

                if (snapshot.data == ORIENTATION.PORTRAIT) {
                  SystemChrome.setPreferredOrientations(
                      [DeviceOrientation.portraitUp]);
                  return 
                } else {
                  SystemChrome.setPreferredOrientations(
                      [DeviceOrientation.landscapeLeft]);

                  return buildLandScape();
                }
              },
            ), */
            Positioned(
              top: minHeight * 8,
              child: buildcameraWindow(),
            ),
          ],
        ),
      ),
    );
  }

  Widget buildcameraWindow() {
    print(shapeItems.length);
    return RouteCameraView(
      cameraButton.stream,
      materialColor,
      shape,
    );
  }

  Stack buildLandScape() {
    return Stack(
      children: [
        buildSettingsButtonLandScape(),
        buildCamButtonLandScape(),
      ],
    );
  }

  Stack buildPortrait() {
    return Stack(
      children: [
        buildCamButtonPortrait(),
        buildSettingsButtonPortrait(),
        buildFlashLightTogglePortrait()
      ],
    );
  }

  Positioned buildCamButtonLandScape() {
    return Positioned(
      right: 1,
      child: Container(
        width: minWidth * 15,
        height: maxHeight,
        color: Colors.amber,
        alignment: Alignment.center,
        child: Container(
          child: IconButton(
            iconSize: minWidth * 10,
            padding: EdgeInsets.all(0),
            icon: Icon(
              Icons.ac_unit,
              color: Colors.white,
            ),
            onPressed: () {
              cameraButton.add(CAMSTATE.PRESSED);
              print("Cam pressed!");
            },
          ),
        ),
      ),
    );
  }

  Positioned buildSettingsButtonLandScape() {
    return Positioned(
      left: minWidth * 1,
      top: minHeight * 1,
      child: Container(
        width: minWidth * 8,
        height: minHeight * 15,
        color: Colors.black,
        alignment: Alignment.center,
        child: Container(
          child: Material(
            color: Colors.transparent,
            child: IconButton(
              iconSize: minHeight * 9,
              icon: Icon(
                Icons.settings,
                color: Colors.white,
              ),
              onPressed: () {},
            ),
          ),
        ),
      ),
    );
  }

  Positioned buildCamButtonPortrait() {
    return Positioned(
      bottom: 0,
      child: Container(
        width: maxWidth,
        height: minHeight * 15,
        alignment: Alignment.center,
        color: Colors.black,
        child: Container(
          child: IconButton(
            iconSize: minHeight * 10,
            padding: EdgeInsets.all(0),
            icon: Icon(
              Icons.ac_unit,
              color: Colors.white,
            ),
            onPressed: () {
              cameraButton.add(CAMSTATE.PRESSED);
              print("Cam pressed!");
            },
          ),
        ),
      ),
    );
  }

  Positioned buildSettingsButtonPortrait() {
    return Positioned(
      left: minWidth,
      top: minHeight * 0.5,
      child: Container(
        color: Colors.black,
        alignment: Alignment.center,
        child: Container(
          child: Material(
            color: Colors.transparent,
            child: DropdownButton(
              items: menuItems,
              icon: Icon(
                Icons.settings,
                color: Colors.white,
              ),
              iconSize: minWidth * 9,
              onTap: () {},
              onChanged: (_) {},
              elevation: 0,
            ),
          ),
        ),
      ),
    );
  }

  Positioned buildFlashLightTogglePortrait() {
    return Positioned(
      right: minWidth * 1,
      top: minHeight * 0.5,
      child: Container(
        width: minWidth * 15,
        height: minHeight * 8,
        color: Colors.black,
        alignment: Alignment.center,
        child: Container(
          child: Material(
            color: Colors.transparent,
            child: IconButton(
              icon: buildFlashIcon(),
              iconSize: minWidth * 9,
              onPressed: flashToggle,
            ),
          ),
        ),
      ),
    );
  }

  Icon buildFlashIcon() {
    if (flashstatus == FLASHSTATUS.OFF) {
      return Icon(
        Icons.flash_off,
        color: Colors.white,
      );
    } else {
      return Icon(
        Icons.flash_on,
        color: Colors.white,
      );
    }
  }

  void flashToggle() async {
    if (flashstatus == FLASHSTATUS.OFF) {
      await TorchCompat.turnOn();
      flashstatus = FLASHSTATUS.ON;
      setState(() {});
    } else {
      await TorchCompat.turnOff();

      flashstatus = FLASHSTATUS.OFF;
      setState(() {});
    }
  }
}
