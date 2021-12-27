const reviews=[
    {
        id:1,
        name:"Aniket Saurav",
        job: "web developer",
        img: "images/img1.jpg",
        text:"Lorem ipsum dolor sit amet consectetur, adipisicing elit. Quidem fugit non cumque, repudiandae tenetur aspernatur quisquam inventore dolorum corporis ratione voluptas quibusdam at sit perspiciatis neque perferendis laborum eveniet expedita.",
    },
    {
        id:2,
        name:"Saurav Sharma",
        job: "Android developer",
        img: "images/img2.jpg",
        text:"sdl sodfie lhdfvo lerf sdlf consectetur, adipisicing elit. Quidem fugit non cumque, repudiandae tenetur aspernatur quisquam invsldf oies oei rum corporis ratione voluptas quibusdam at sit perspiciatis neque perferendis laborum eveniet expedita.",
    },
    {
        id:3,
        name:"Vikash kumar",
        job: "UX designer",
        img: "images/img3.jpg",
        text:"sdl sodfie lhdfvo lerf sdlf consectetur, adipisicing elit. Quidem fugit non cumque, repudiandae tenetur aspernatur quisquam invsldf oies oei rum corporis ratione voluptas quibusdam at sit perspiciatis neque perferendis laborum eveniet expedita.",
    },
    {
        id:4,
        name:"Akshat Kedia",
        job: "Crypto Trader",
        img: "images/img4.jpg",
        text:"fsifjaiodf ais fa roigjajdiga gaiorshgahg oa rga goiarg  aoisdf atur quisquam invsldf oies oei rum corporis ratione voluptas quibusdam at sit perspiciatis neque perferendis laborum eveniet expedita.",
    },
];

const image= document.getElementById("person-img");
const aurthor= document.getElementById("author");
const jobs= document.getElementById("job");
const info= document.getElementById("info");
// console.log(image);

const prevbtn= document.querySelector('.prev-btn');
const nextbtn= document.querySelector('.next-btn');
const randombtn= document.querySelector('.random-btn');
let currentItem=0;

//load initial item

window.addEventListener("DOMContentLoaded", function(){
    const item=reviews[currentItem];
    image.src=item.img;
    aurthor.textContent=item.name;
    jobs.textContent=item.job;
    info.textContent=item.text;

});
nextbtn.addEventListener("click",function(){
    currentItem++;
    // console.log(currentItem);
    if(currentItem>=reviews.length){
        currentItem=0;
    }
    const item=reviews[currentItem];
    image.src=item.img;
    aurthor.textContent=item.name;
    jobs.textContent=item.job;
    info.textContent=item.text;
});
prevbtn.addEventListener("click",function(){
    currentItem--;
    // console.log(currentItem);
    if(currentItem<0){
        currentItem=reviews.length-1;
    }
    console.log(currentItem);
    const item=reviews[currentItem];
    image.src=item.img;
    aurthor.textContent=item.name;
    jobs.textContent=item.job;
    info.textContent=item.text;
});


