import 'package:flutter/material.dart';
import 'package:arcore_flutter_plugin/arcore_flutter_plugin.dart';
import 'package:vector_math/vector_math_64.dart' as vector;
import 'package:augment_zero/Utility/Class_OrientationObserver.dart';

enum CAMSTATE {
  PRESSED,
  NONE,
}

class RouteCameraView extends StatefulWidget {
  final String materialColor;
  final String shape;
  final Stream<CAMSTATE> cameraButtonStream;
  RouteCameraView(this.cameraButtonStream, this.materialColor, this.shape,
      {Key key})
      : super(key: key);
  @override
  _RouteCameraViewState createState() => _RouteCameraViewState();
}

class _RouteCameraViewState extends State<RouteCameraView>
    with ClassOrientationObserver {
  _RouteCameraViewState() {
    setConstraints();
  }
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

  void dispose() {
    arCoreController.dispose();

    super.dispose();
  }

  Widget build(BuildContext context) {
    return Container(
      width: maxWidth,
      height: maxHeight - (minHeight * 23),
    );
  }
}
