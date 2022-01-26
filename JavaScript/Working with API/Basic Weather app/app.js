let weather{
    apiKey:"5aa25c9899e4317110a9d05bd9cc8b30",
    fetchWeather: function () {
        fetch("https://api.openweathermap.org/data/2.5/weather?q=delhi&units=metric&appid=5aa25c9899e4317110a9d05bd9cc8b30").then((response)=> response.json()).then((data)=>console.log(data))
    },
};
console.log("this is it");






