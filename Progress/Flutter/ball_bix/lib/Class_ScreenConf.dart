

class ScreenConf
{
  static double maxHeight=1;
  static double minHeight=0;
  static double maxWidth=1;
  static double minWidth=0;
  
  void init(double height,double width)
  {
    maxHeight=height;
    maxWidth=width;
    minHeight=height/100;
    minWidth=width/100;

  }

}