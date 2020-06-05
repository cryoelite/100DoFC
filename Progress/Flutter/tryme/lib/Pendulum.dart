import 'dart:math';

class Pendulum {
  int x, y, k, h, r, temp = 0;
  Pendulum({this.x = 0, this.y = 0, this.h = 0, this.k = 0, this.r = 0}) {
    x = x - h;
    y = y - k;
  }
  void updater() {
    switch (temp ~/ r) {
      case 0:
        {
          x += 1;
          y = calc();
          break;
        }
      case 1:
        {
          x -= 1;
          y = -calc();
          break;
        }
      case 2:
        {
          x -= 1;
          y = -calc();
          break;
        }
      case 3:
        {
          x += 1;
          y = calc();
          break;
        }
    }
    temp += 1;
    print(temp);
    print("$x,$y");
  }

  int calc() {
    final temp = (sqrt(pow(r, 2) - pow(x, 2))).toInt();
    return temp;
  }

  int get xAxis => this.x;
  int get yAxis => this.y;
}
