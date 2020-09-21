import 'package:flutter/material.dart';

class ClassBallGenerator extends CustomPainter {
  Offset sigma = Offset.zero;
  ClassBallGenerator(this.sigma);

  @override
  void paint(Canvas canvas, Size size) {
    Paint paint = Paint()
      ..color = Colors.black
      ..style = PaintingStyle.fill
      ..strokeWidth = 3;

    canvas.drawCircle(sigma, 10, paint);
  }

  bool shouldRepaint(_) => false;

  void update(Offset temp) => sigma = temp;
}
