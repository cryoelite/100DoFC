import 'package:flutter/material.dart';
import 'package:arcore_flutter_plugin/arcore_flutter_plugin.dart';

import 'package:augment_zero/Utility/Class_ScreenConf.dart';

class RouteHome extends StatefulWidget {
  final double maxHeight;
  final double minHeight;
  final double maxWidth;
  final double minWidth;
  final ClassScreenConf getClass;

  RouteHome(BuildContext context, {Key key})
      : getClass = ClassScreenConf(context),
        minWidth = ClassScreenConf.minWidth,
        maxWidth = ClassScreenConf.maxHeight,
        maxHeight = ClassScreenConf.maxHeight,
        minHeight = ClassScreenConf.minHeight,
        super(key: key);
  @override
  _RouteHomeState createState() => _RouteHomeState();
}

class _RouteHomeState extends State<RouteHome> {
  @override
  Widget build(BuildContext context) {
    print("Yoo ${widget.maxWidth}");
    return Scaffold(
      backgroundColor: Colors.black,
      body: Container(
        width: widget.maxWidth,
        height: widget.maxHeight,
        
        child: Stack(
          children: <Widget>[
            Positioned(
              right: widget.minWidth * 2,
              child: Container(
                width: widget.minWidth*20,
                height: widget.minHeight*10,
                alignment: Alignment.centerLeft,
                child: Material(
                  color: Colors.transparent,
                  child: IconButton(
                    icon: Icon(
                      Icons.menu,
                      color: Colors.white,
                    ),
                    onPressed: () {},
                  ),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
