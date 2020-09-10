import 'dart:async';

import 'package:sensors/sensors.dart';

import 'package:augment_zero/Utility/Class_ScreenConf.dart';

enum ORIENTATION {
  LANDSCAPE,
  PORTRAIT,
}
mixin ClassOrientationObserver {
  final StreamController<ORIENTATION> accelStreamClr =
      StreamController<ORIENTATION>();
  double minWidth;
  double maxWidth;
  double maxHeight;
  double minHeight;

  void setConstraints() {
    minWidth = ClassScreenConf.minWidth;
    maxWidth = ClassScreenConf.maxWidth;
    maxHeight = ClassScreenConf.maxHeight;
    minHeight = ClassScreenConf.minHeight;
  }

  void startObserver() {
    accelerometerEvents.listen((AccelerometerEvent event) {
      final int y = event.y.floor();
      final int x = event.x.floor();
      if ((x - y).abs() < 4) {
        accelStreamClr.add(ORIENTATION.PORTRAIT);
      } else if (y <= 5 && y >= -5) {
        accelStreamClr.add(ORIENTATION.LANDSCAPE);
      } else {
        accelStreamClr.add(ORIENTATION.PORTRAIT);
      }
    });
  }

  void stopObserver() {
    accelStreamClr.close();
  }
}
