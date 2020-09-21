import 'package:ball_bix/Route_HomePage.dart';
import 'package:flutter/material.dart';

import './Class_ScreenConf.dart';

class RouteScaffold extends StatefulWidget {
  RouteScaffold(BuildContext context, {Key key}) : super(key: key) {
    ScreenConf().init(
        MediaQuery.of(context).size.height, MediaQuery.of(context).size.width);
  }
  @override
  _RouteScaffoldState createState() => _RouteScaffoldState();
}

class _RouteScaffoldState extends State<RouteScaffold> {
  RouteHomePage routeHomePage = RouteHomePage();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: SafeArea(
        child: Container(
          width: ScreenConf.maxWidth,
          height: ScreenConf.maxHeight,
          decoration: BoxDecoration(
            border: Border.all(
              width: ScreenConf.minWidth * 5,
              color: Theme.of(context).primaryColor,
            ),
          ),
          child: Stack(
            children: [
              routeHomePage,
            ],
          ),
        ),
      ),
    );
  }
}
