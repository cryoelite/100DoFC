import 'dart:async';

import 'package:flutter/material.dart';

import 'package:augment_zero/Utility/Class_ScreenConf.dart';
import 'package:augment_zero/FirstRoute/Route_CameraView.dart';

class RouteHome extends StatefulWidget {
  final double maxHeight;
  final double minHeight;
  final double maxWidth;
  final double minWidth;
  final ClassScreenConf getClass;

  RouteHome(BuildContext context, {Key key})
      : getClass = ClassScreenConf(context),
        minWidth = ClassScreenConf.minWidth,
        maxWidth = ClassScreenConf.maxWidth,
        maxHeight = ClassScreenConf.maxHeight,
        minHeight = ClassScreenConf.minHeight,
        super(key: key);
  @override
  _RouteHomeState createState() => _RouteHomeState();
}

class _RouteHomeState extends State<RouteHome> {
  StreamController<CAMSTATE> cameraButton = StreamController<CAMSTATE>();

  @override
  void dispose() {
    cameraButton.close();
    super.dispose();
  }

  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      body: Container(
        width: widget.maxWidth,
        height: widget.maxHeight,
        child: Stack(
          children: <Widget>[
            Positioned(
              right: widget.minWidth * 1,
              top: widget.minHeight * 1,
              child: Container(
                width: widget.minWidth * 15,
                height: widget.minHeight * 8,
                color: Colors.black,
                alignment: Alignment.centerLeft,
                child: Material(
                  color: Colors.transparent,
                  child: IconButton(
                    splashRadius: widget.minWidth * 6,
                    icon: Icon(
                      Icons.settings,
                      color: Colors.white,
                    ),
                    onPressed: () {},
                  ),
                ),
              ),
            ),
            Positioned(
              top: widget.minHeight * 8,
              child: RouteCameraView(cameraButton.stream),
            ),
            Positioned(
              bottom: 0,
              child: Container(
                width: widget.maxWidth,
                height: widget.minHeight * 20,
                color: Colors.black,
                alignment: Alignment.center,
                child: IconButton(
                  iconSize: widget.minHeight * 10,
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
          ],
        ),
      ),
    );
  }
}
