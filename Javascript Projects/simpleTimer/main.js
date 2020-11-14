// Set the date we're counting down to
// var countDownDate = new Date("Jan 5, 2021 15:37:25").getTime();
var repeat = false;

document.getElementById("rep").addEventListener("change", ()=>{
    repeat=!repeat;
    console.log(repeat);
});

function startTimer() {
    // Update the count down every 1 second
    
    var ttgt = document.getElementById("amt").value;
    var tgt = ttgt * 60;

    var counter = 0;

    var x = setInterval(function() {
        // console.log(tgt);
        

        mins = Math.floor(tgt / 60);
        secs = tgt % 60;

        // Display the result in the element with id="demo"
        document.getElementById("demo").style = "color: black";
        document.getElementById("demo").innerHTML = "Time remaining: " + mins + ":" + secs;
        tgt--;
        // If the count down is finished, write some text
        if (tgt < 0 && !repeat) {
            clearInterval(x);
            document.getElementById("demo").innerHTML = "EXPIRED";
            document.getElementById("demo").style = "color: red";
            document.getElementById("ding").play()
        }
        else if (tgt < 0 && repeat) {
            counter++;
            document.getElementById("counter").innerHTML = "Counter = " + counter;
            document.getElementById("ding").play()
            tgt = ttgt * 60;
        }
        
    }, 1000);
       
    
}