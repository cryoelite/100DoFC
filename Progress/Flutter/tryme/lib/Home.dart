import 'dart:async';

import 'package:flare_flutter/flare_controls.dart';
import 'package:flutter/material.dart';

import 'package:flare_flutter/flare_actor.dart';
import 'package:tryme/routeConf.dart';

class Homer extends StatefulWidget {
  @override
  _HomerState createState() => _HomerState();
}

class _HomerState extends State<Homer> with SingleTickerProviderStateMixin {
  final FlareControls controls = FlareControls();

  Widget thisAnime() {
    return FlareActor(
      'lib/spiner.flr',
      animation: "spin",
      controller: controls,
      callback: (_) {
        controls.play("spin");  
        Timer.periodic(Duration(seconds: 3), (_) {
          print("Spin spin");
          controls.play("spin");
        });
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    ScreenConf().init(context);
    return Scaffold(
      body: SafeArea(
        child: Container(
          width: ScreenConf.hArea,
          height: ScreenConf.vArea,
          child: thisAnime(),
        ),
      ),
    );
  }
}
