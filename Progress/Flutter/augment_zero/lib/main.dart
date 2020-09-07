import 'package:flutter/material.dart';

import 'package:augment_zero/FirstRoute/Route_Home.dart';

import 'package:augment_zero/Utility/Class_ScreenConf.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  runApp(MainApp());
}

class MainApp extends StatefulWidget {

  @override
  _MainAppState createState() => _MainAppState();
}

class _MainAppState extends State<MainApp> {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      initialRoute: '/',
      routes: {
        '/': (context) => RouteHome(context),
      },
    );
  }
}
