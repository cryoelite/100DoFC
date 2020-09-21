import 'package:flutter/gestures.dart';
import 'package:flutter/material.dart';

import './Class_BallGenerator.dart';
import './Class_ScreenConf.dart';

class RouteHomePage extends StatefulWidget {
  @override
  _RouteHomePageState createState() => _RouteHomePageState();
}

class _RouteHomePageState extends State<RouteHomePage> {
  bool isBallGenerated = false;
  ClassBallGenerator ball;

  List<CustomPaint> paintObjects = [];

  void addPaintObject(Offset details) {
    ClassBallGenerator ball = ClassBallGenerator(details);
    paintObjects.add(
      CustomPaint(
        painter: ball,
      ),
    );
    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      child: GestureDetector(
        onPanStart: (details) {
          isBallGenerated = true;
          addPaintObject(details.localPosition);
          print("Touch made");
        },
        onPanUpdate: (details) {
          addPaintObject(details.localPosition);
          print("${details.localPosition.toString()}");
        },
        child: Container(
          color: Colors.white,
          width: ScreenConf.maxWidth,
          height: ScreenConf.maxHeight,
          child: isBallGenerated
              ? Stack(
                  children: paintObjects,
                )
              : Container(),
        ),
      ),
    );
  }
}
