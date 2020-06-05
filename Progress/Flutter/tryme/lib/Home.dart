import 'dart:async';

import 'package:flutter/material.dart';

import './Pendulum.dart';
import './routeConf.dart';

class Homer extends StatefulWidget {
  @override
  _HomerState createState() => _HomerState();
}

class _HomerState extends State<Homer> with SingleTickerProviderStateMixin {
  static const r = 60;
  Pendulum swing = Pendulum(r: r);
  StreamController s1 = StreamController();
  int time = 0;
  Timer t1;
  int x = 0, y = 0;
  void startTimer() {
    this.t1 = Timer.periodic(Duration(milliseconds: 17), (_) {
      swing.updater();
      setState(() {
        this.x = swing.xAxis;
        this.y = swing.yAxis;
      });
      s1.sink.add(time += 1);
    });
  }

  void initState() {
    super.initState();
    streamIt();
  }

  void streamIt() {
    startTimer();
    StreamSubscription streamer;
    Stream stream = s1.stream;
    streamer = stream.listen((event) {
      if (event == _HomerState.r * 4) {
        streamer.cancel();
        s1.close();
        t1.cancel();
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    RouterConf().init(context);
    return Scaffold(
      body: buildContainer(),
    );
  }

  Container buildContainer() {
    return Container(
      height: double.infinity,
      width: double.infinity,
      color: Colors.white,
      child: Stack(
        children: <Widget>[
          Positioned(
            left: RouterConf.blockH * 40,
            top: RouterConf.blockH * 110,
            child: Container(
              width: RouterConf.blockH * 20,
              height: RouterConf.blockH * 20,
              child: CustomSingleChildLayout(
                delegate: DrawIt(this.x, this.y),
                child: Stack(
                  children: <Widget>[
                    CustomPaint(
                      painter: DrawDot(this.x, this.y),
                    ),
                    Icon(
                      Icons.blur_circular,
                      color: Colors.amber,
                      size: 60,
                    ),
                  ],
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}

class DrawIt extends SingleChildLayoutDelegate {
  double x, y;
  DrawIt(x, y) {
    this.x = x.toDouble();
    this.y = -y.toDouble();
  }
  @override
  Offset getPositionForChild(Size size, Size childSize) {
    return Offset(this.x, this.y);
  }

  bool shouldRelayout(_) => true;
}

class DrawDot extends CustomPainter {
  double x, y;
  DrawDot(x, y) {
    this.x = x.toDouble();
    this.y = -y.toDouble();
  }
  @override
  void paint(Canvas canvas, Size size) {
    Paint panel = Paint();
    panel.color = Colors.deepOrange;
    canvas.drawCircle(Offset(this.x, this.y), 5, panel);
  }

  bool shouldRepaint(_) => false;
}
