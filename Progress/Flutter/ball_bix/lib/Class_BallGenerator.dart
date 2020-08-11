import 'package:flutter/material.dart';

class ClassBallGenerator extends CustomPainter {
  Offset sigma = Offset.zero;
  ClassBallGenerator(this.sigma);

  @override
  void paint(Canvas canvas, Size size) {
    Paint paint = Paint()
      ..color = Colors.black
      ..style = PaintingStyle.stroke
      ..strokeWidth = 3;

    canvas.drawCircle(sigma, 10, paint);
  }

  bool shouldRepaint(_) => true;

  void update(Offset temp) => sigma = temp;
}
