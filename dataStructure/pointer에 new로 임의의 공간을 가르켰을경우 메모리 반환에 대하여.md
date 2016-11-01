function1(){<br>
  int * p;<br>
  int a;<br>
  p = &a;<br>
}<br>
의 경우 자동으로 메모리가 다 반환이 된다<br>
<br>
function2(){<br>
  int * p;<br>
  p = new int;<br>
}<br>
의 경우 자동으로 메모리반환이 되지 않으므로 delete p를 해주어야함.<br>
