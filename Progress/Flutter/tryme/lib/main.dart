import 'package:flutter/material.dart';

import './Home.dart';

void main() => runApp(Mainly());

class Mainly extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      initialRoute: '/',
      routes: {
        '/': (context) => Homer(),
      },
    );
  }
}
