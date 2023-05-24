const colors =[0,1,2,3,4,5,6,7,8,9,"A","B","C","D","E","F"];

const btn = document.getElementById("btn");
const color= document.querySelector(".color");
const min=0;
const max=colors.length;
btn.addEventListener('click',function(){
    let hexcolor="#";
    for(let i = 0; i < 6; i++){
        let randomNumber=randomIntFromInterval(0,15);
        hexcolor+=colors[randomNumber];
    }
    console.log(hexcolor);
    color.textContent=hexcolor;
    document.body.style.backgroundColor=hexcolor;

})
//function for returning random number btwn min and max value
function randomIntFromInterval(min, max) { 
    return Math.floor(Math.random() * (max - min + 1) + min)
}