import 'package:flutter/material.dart';

import './Pendulum.dart';

class Homer extends StatefulWidget {
  @override
  _HomerState createState() => _HomerState();
}

class _HomerState extends State<Homer> with SingleTickerProviderStateMixin {
  AnimationController _animCont;

  @override
  void initState() {
    super.initState();
    _animCont =
        AnimationController(duration: Duration(seconds: 15), vsync: this);
    _animCont.repeat();
  }

  void dispose() {
    _animCont.dispose();
    super.dispose();
  }

  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        width: 390,
        height: 800,
        child: Stack(
          children: <Widget>[
            Positioned(
              top: 380,
              child: RotationTransition(
                turns: _animCont,
                alignment: Alignment.center,
                child: Container(
                  width: 390,
                  height: 200,
                  child: Center(
                    child: Icon(
                      Icons.ac_unit,
                      size: 150,
                    ),
                  ),
                ),
              ),
            ),
            Positioned(
              top: 380,
              child: Container(
                color: Colors.black12,
                width: 390,
                height: 200,
                child: Icon(Icons.access_time),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
