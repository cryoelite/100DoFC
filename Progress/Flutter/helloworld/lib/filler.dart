import 'package:flutter/material.dart';

import './staticFolder/outp.dart';

class First extends StatefulWidget {
  @override
  _FirstState createState() => _FirstState();
}

class _FirstState extends State<First> {
  var i = 0;
  var op = Outp(["Hello", "Welcome", "To", "My", "First", "App"]);
  void setter() {
    setState(() {
      if (i < (op.outPData.length) - 1) {
        i += 1;
      } else {
        i = 0;
      }
    });
  }

  Container buildCont() {
    if (i == (op.outPData.length) - 1) {
      return Container(
        width: double.infinity,
        height: double.infinity,
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              op.outPData[i],
              style: TextStyle(color: Colors.blue, fontSize: 28),
            ),
          ],
        ),
      );
    } else {
      return Container(
        width: double.infinity,
        height: double.infinity,
        child: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              op.outPData[i],
              style: TextStyle(color: Colors.blue, fontSize: 28),
            ),
          ],
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Material(
      color: Colors.black,
      child: InkWell(
        onTap: setter,
        child: buildCont(),
      ),
    );
  }
}
