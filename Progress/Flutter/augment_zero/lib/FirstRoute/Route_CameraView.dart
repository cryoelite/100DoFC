import 'package:flutter/material.dart';
import 'package:arcore_flutter_plugin/arcore_flutter_plugin.dart';
import 'package:vector_math/vector_math_64.dart' as vector;
import 'package:flutter/services.dart';

import 'package:augment_zero/Utility/Class_OrientationObserver.dart';

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

  Widget build(BuildContext context) {
    return StreamBuilder<ORIENTATION>(
      stream: accelStreamClr.stream,
      builder: (context, AsyncSnapshot<ORIENTATION> snapshot) {
        if (snapshot.data == ORIENTATION.PORTRAIT) {
          SystemChrome.setPreferredOrientations([DeviceOrientation.portraitUp]);
          setConstraints();

          return buildPortrait();
        } else {
          SystemChrome.setPreferredOrientations(
              [DeviceOrientation.landscapeLeft]);
          setConstraints();

          return buildLandScape();
        }
      },
    );
  }

  Widget buildPortrait() {
    return Container(
      width: maxWidth,
      height: maxHeight - (minHeight * 23),
      child: ArCoreView(
        onArCoreViewCreated: onArCoreViewCreated,
      ),
    );
  }

  Widget buildLandScape() {
    return Container(
      width: maxHeight,
      height: maxWidth - (minWidth * 23),
      child: ArCoreView(
        onArCoreViewCreated: onArCoreViewCreated,
      ),
    );
  }
}
