import 'package:flutter/material.dart';
import 'package:arcore_flutter_plugin/arcore_flutter_plugin.dart';
import 'package:vector_math/vector_math_64.dart' as vector;
import 'package:augment_zero/Utility/Class_OrientationObserver.dart';

enum CAMSTATE {
  PRESSED,
  NONE,
}

enum SHAPE { SPHERE, CUBE, CYLINDER }

class RouteCameraView extends StatefulWidget {
  final Stream<CAMSTATE> cameraButtonStream;
  RouteCameraView(this.cameraButtonStream, {Key key}) : super(key: key);
  @override
  RouteCameraViewState createState() => RouteCameraViewState();
}

class RouteCameraViewState extends State<RouteCameraView>
    with ClassOrientationObserver {
  RouteCameraViewState() {
    setConstraints();
  }
  ArCoreController arCoreController;

  void onArCoreViewCreated(ArCoreController tempController) {
    arCoreController = tempController;
  }

  void addItem(SHAPE tempShape, Color color) {
    switch (tempShape) {
      case SHAPE.SPHERE:
        {
          addSphere(color);
          break;
        }
      case SHAPE.CYLINDER:
        {
          addCube(color);
          break;
        }
      case SHAPE.CUBE:
        {
          addCylinder(color);
          break;
        }
      default:
        {
          break;
        }
    }
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

  void addCube(Color color) {}

  void addCylinder(Color color) {}

  void addSphere(Color color) {
    final material = ArCoreMaterial(
      color: color,
    );
    final sphere = ArCoreSphere(
      materials: [material],
      radius: 10,
    );
    final node = ArCoreNode(
      shape: sphere,
      position: vector.Vector3(0, 0, -1.5),
    );
    arCoreController.addArCoreNode(node);
  }

  Widget build(BuildContext context) {
    return Container(
      width: maxWidth,
      height: maxHeight - (minHeight * 23),
      child: ArCoreView(
        onArCoreViewCreated: onArCoreViewCreated,
        type: ArCoreViewType.STANDARDVIEW,
      ),
    );
  }
}
