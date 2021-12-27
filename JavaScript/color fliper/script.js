const colors =["green","red","blue","#f45d54"];

const btn = document.getElementById("btn");
const color= document.querySelector(".color");
const min=0;
const max=colors.length;
btn.addEventListener('click',function(){
    //choosing ramdom number between 0-3
    const randomNumber=randomIntFromInterval(min,max);
    console.log(randomNumber);
    document.body.style.backgroundColor=colors[randomNumber];
    color.textContent=colors[randomNumber];

})
//function for returning random number btwn min and max value
function randomIntFromInterval(min, max) { 
    return Math.floor(Math.random() * (max - min + 1) + min)
}

