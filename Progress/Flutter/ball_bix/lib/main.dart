import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import './Route_HomePage.dart';
import './Route_Scaffold.dart';

void main() {
  runApp(BallBix());
}

class BallBix extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setEnabledSystemUIOverlays([SystemUiOverlay.top]);
    return MaterialApp(
      theme: ThemeData(
        primaryColor: Colors.orange[200],
      ),
      debugShowCheckedModeBanner: false,
      initialRoute: '/',
      routes: {
        '/': (context) => RouteScaffold(context),
        '/RouteHomePage': (_) => RouteHomePage(),
      },
    );
  }
}
