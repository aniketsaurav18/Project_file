const modal_btn=document.querySelector(".modal-btn");
console.log(modal_btn);
const modal_close_btn=document.querySelector(".close-btn")
const modal_overlay=document.querySelector(".modal-overlay");

modal_btn.addEventListener("click",function(){
    modal_overlay.classList.add("close-modal");
});
modal_close_btn.addEventListener("click",function(){
    modal_overlay.classList.remove("close-modal");
});