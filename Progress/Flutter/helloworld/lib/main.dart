import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import './filler.dart';
void main() => runApp(M1());

class M1 extends StatefulWidget {
  @override
  _M1State createState() => _M1State();
}

class _M1State extends State<M1> {
  
  @override
  Widget build(BuildContext context) {
    SystemChrome.setEnabledSystemUIOverlays ([SystemUiOverlay.bottom]);
    return MaterialApp(
      home: Scaffold(
        body: First(),
      ),
    );
  }
}
