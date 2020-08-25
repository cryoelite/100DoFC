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

  @override
  Widget build(BuildContext context) {
    return Container(
      child: GestureDetector(
        onPanStart: (details) {
          ball = ClassBallGenerator(details.localPosition);
          isBallGenerated = true;
          setState(() {});
          print("Touch made");
        },
        onPanUpdate: (details) {
          ball=ClassBallGenerator(details.localPosition);
          setState(() {});
          print("${details.localPosition.toString()}");
        },
        child: Container(
          color: Colors.white,
          width: ScreenConf.maxWidth,
          height: ScreenConf.maxHeight,
          child: isBallGenerated
              ? CustomPaint(
                  painter: ball,
                )
              : Container(),
        ),
      ),
    );
  }
}
