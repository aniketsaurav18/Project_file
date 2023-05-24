var header = document.getElementById("myDIV");
var btns = document.querySelectorAll("nav-btn");
console.log(btns);
for (var i = 0; i < btns.length; i++) {
  btns[i].addEventListener("click", function() {
  var current = document.getElementsByClassName("is-active");
  if (current.length > 0) { 
    current[0].className = current[0].className.replace("is-active", "");
  }
  this.className += "is-active";
  });
}