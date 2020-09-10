import 'dart:async';

import 'package:flutter/material.dart';

import 'package:augment_zero/Utility/Class_ScreenConf.dart';
import 'package:augment_zero/FirstRoute/Route_CameraView.dart';
import 'package:augment_zero/Utility/Class_OrientationObserver.dart';
import 'package:flutter/services.dart';

class RouteHome extends StatefulWidget {
  final ClassScreenConf getClass;

  RouteHome(BuildContext context, {Key key})
      : getClass = ClassScreenConf(context),
        super(key: key);
  @override
  _RouteHomeState createState() => _RouteHomeState();
}

class _RouteHomeState extends State<RouteHome> with ClassOrientationObserver {
  StreamController<CAMSTATE> cameraButton = StreamController<CAMSTATE>();

  _RouteHomeState() {
    setConstraints();
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
    return Scaffold(
      backgroundColor: Colors.black,
      body: StreamBuilder<ORIENTATION>(
        stream: accelStreamClr.stream,
        builder: (context, AsyncSnapshot<ORIENTATION> snapshot) {
          if (snapshot.data == ORIENTATION.PORTRAIT) {
            SystemChrome.setPreferredOrientations(
                [DeviceOrientation.portraitUp]);
            setConstraints();

            return buildPortrait();
          } else {
            SystemChrome.setPreferredOrientations(
                [DeviceOrientation.landscapeLeft]);
            setConstraints();

            return buildLandScape();
          }
        },
      ),
    );
  }

  Container buildLandScape() {
    return Container(
      width: maxWidth,
      height: maxHeight,
      child: Stack(
        children: <Widget>[
          Positioned(
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
          ),
          Positioned(
            left: minWidth * 8,
            child: RouteCameraView(cameraButton.stream),
          ),
          Positioned(
            right: 1,
            child: Container(
              width: minWidth * 15,
              height: maxHeight,
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
          ),
        ],
      ),
    );
  }

  Container buildPortrait() {
    return Container(
      width: maxWidth,
      height: maxHeight,
      child: Stack(
        children: <Widget>[
          Positioned(
            left: minWidth * 1,
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
                    iconSize: minWidth * 9,
                    icon: Icon(
                      Icons.settings,
                      color: Colors.white,
                    ),
                    onPressed: () {},
                  ),
                ),
              ),
            ),
          ),
          Positioned(
            top: minHeight * 8,
            child: RouteCameraView(cameraButton.stream),
          ),
          Positioned(
            bottom: 0,
            child: Container(
              width: maxWidth,
              height: minHeight * 15,
              alignment: Alignment.center,
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
          ),
        ],
      ),
    );
  }
}
