import 'package:flutter/material.dart';

class Pendulum extends CustomPainter {
  @override
  bool shouldRepaint(CustomPainter _) => true;

  void paint(Canvas canvas, Size size) {
    Paint paint = Paint();
    paint.color = Colors.blueGrey[400];
    paint.style = PaintingStyle.stroke;
    paint.strokeWidth = 5.0;

    var w = size.width;
    var h = size.height;
    Path path = Path();
    path.lineTo(w / (2 * 100 / 135), h / 2);
    path.lineTo(0, h);
    path.moveTo(w, 0);
    path.lineTo(w / (2 * 100 / 65), h / 2);
    path.lineTo(w, h);
    path.moveTo(0, 0);
    path.moveTo(w / 2, h / 2.7);
    path.lineTo(w / 2, 0);
    path.moveTo(w / 2, (-h / 2.7) + h);
    path.lineTo(w / 2, h);
    path.close();
    canvas.drawPath(path, paint);
  }
}
