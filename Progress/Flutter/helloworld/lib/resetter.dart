import 'package:flutter/material.dart';

class Reset extends StatelessWidget {
  int i;
  Reset(this.i);
  @override
  Widget build(BuildContext context) {
    return Container(
      child: RaisedButton(

        onPressed: () => i=0),
    );
  }
}