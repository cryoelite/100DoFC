import 'package:flutter/material.dart';

class ClassScreenConf {
  static double maxHeight;
  static double maxWidth;
  static double minHeight;
  static double minWidth;
  static const double divisionFactor = 128;
  ClassScreenConf(BuildContext context) {
    final MediaQueryData mq = MediaQuery.of(context);
    maxHeight = mq.size.height;
    minHeight = mq.size.height / divisionFactor;
    maxWidth = mq.size.width;

    minWidth = mq.size.width / divisionFactor;
  }
}
