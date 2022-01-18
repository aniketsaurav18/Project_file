// var outRequest = new XMLHttpRequest();
// outRequest.open("GET","https://learnwebcode.github.io/json-example/animals-1.json");

// outRequest.onload= function(){
//     // console.log(outRequest.responseText);
//     var ourData = JSON.parse(outRequest.responseText);
//     console.log(ourData[1]);
// };
// outRequest.send();

const btn= document.getElementById("btn");
var animalContainer = document.getElementById("container");
var pageCounter = 1;
console.log(animalContainer);
// animalContainer.insertAdjacentHTML("beforeend", "hello");


function renderHtml(data){
    var htmlString = "";
    for(i=0;i<data.length; i++){
        htmlString += "<p>"+data[i].name+"is a"+data[i].species+".</p>";
    }
    animalContainer.insertAdjacentHTML("beforeend",htmlString)
}
function showData2(){
    var request= new XMLHttpRequest();
    request.open("GET","https://learnwebcode.github.io/json-example/animals-"+pageCounter+".json");
    request.onload=function(){
        var outData = JSON.parse(request.responseText);
        // console.log(outData[1]);
        renderHtml(outData);

    }
    request.send();
    pageCounter++;
    if(pageCounter>3){
        btn.classList.add("hide");
    }
}
btn.addEventListener("click",showData2);
