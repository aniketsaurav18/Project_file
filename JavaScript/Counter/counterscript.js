let count=0;
const counter= document.getElementById("value");
const select= document.querySelectorAll(".btn");
console.log(select);

select.forEach(function(btns){
    btns.addEventListener("click",function(e){
        const btn=e.currentTarget.classList;
        console.log(btn);
        if(btn.contains("decr")){
            count--;
            counter.textContent=count;
        }else if(btn.contains("incr")){
            count++;
            counter.textContent=count;
        }else if(btn.contains("reset")){
            count=0;
            counter.textContent=count;
        }
        if(count<0){
            counter.style.color="red"; 
        }else{
            counter.style.color="black";
        }
    })
})