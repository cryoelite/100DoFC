import 'package:flutter/material.dart';
import 'package:arcore_flutter_plugin/arcore_flutter_plugin.dart';
import 'package:vector_math/vector_math_64.dart' as vector;

import 'package:augment_zero/Utility/Class_ScreenConf.dart';

enum CAMSTATE {
  PRESSED,
  NONE,
}

class RouteCameraView extends StatefulWidget {
  final Stream<CAMSTATE> cameraButtonStream;
  RouteCameraView(this.cameraButtonStream, {Key key}) : super(key: key);
  @override
  _RouteCameraViewState createState() => _RouteCameraViewState();
}

class _RouteCameraViewState extends State<RouteCameraView> {
  final double minWidth = ClassScreenConf.minWidth;
  final double maxWidth = ClassScreenConf.maxWidth;
  final double maxHeight = ClassScreenConf.maxHeight;
  final double minHeight = ClassScreenConf.minHeight;
  ArCoreController arCoreController;

  void onArCoreViewCreated(ArCoreController tempController) {
    arCoreController = tempController;
  }

  void captureShot() {
    print("Captured");
  }

  @override
  void initState() {
    super.initState();
    widget.cameraButtonStream.listen((CAMSTATE event) {
      if (event == CAMSTATE.PRESSED) {
        captureShot();
      }
    });
  }

  Widget build(BuildContext context) {
    return Container(
      width: maxWidth,
      height: maxHeight - (minHeight * 28),
      child: Container(
        child: ArCoreView(
          onArCoreViewCreated: onArCoreViewCreated,
        ),
      ),
    );
  }
}
