<template>
    <div class = "timer"> 
        
        <div class = "inps"> 
            Repetitions: <input id = "rep" type="number" min="1" v-model="repeat"><br>
            Minutes: <input id = "amt" type="number" min="0" v-model="timeMins"><br>
        </div>
        <div class = "outs">
            <audio id="ding"></audio>
            <button @click="startTimer()">✔</button>
            <button @click="stopPushed=true">❌</button>
            
            <div class = "out" :style = "outstyle" id="output">{{output}}</div>
            <div class = "out" :style = "cntstyle" id="counter">{{cnt}}</div>
        </div>
    </div>
</template>

<script>
    var sounds = {
        'ding': require('../assets/ding3.wav'),
        'done': require('../assets/done.wav')
    }   
    
    export default {
        data() {
            return {
                repeat: 1,
                timeMins: 0,
                output: " ",
                cnt: " ",
                outstyle: "color: black",
                cntstyle: "color: black",
                stopPushed: false,
                isRunning: false,
                ding: new Audio(sounds['ding']),
                done: new Audio(sounds['done'])
            }
        },
        methods: {
            checkTime(i) {
                if (i < 10) {
                i = "0" + i;
                }
                return i;
            },
            startTimer() {
                if (this.isRunning) return;
                
                
                this.output = "";
                this.cnt = "";
                this.outstyle = "color: black";
                
                this.isRunning = true;    
                this.stopPushed = false;

                var audio = new Audio('');
                // Grab control for mobile playback of sound
                audio.play();
                
                // Set source of sound
                //var ding = new Audio('./ding3.wav');

                var timeSecs = this.timeMins * 60;
                var counter = 0;
                var vm = this;

                // Reset display
                
                var x = setInterval(function () {
                    
                    
                    // If stop button is pushed
                    if (vm.stopPushed) {
                        clearInterval(x);
                        vm.output = "STOPPED";
                        vm.outstyle = "color: green;";
                        vm.stopPushed = false;
                        vm.isRunning = false;
                        return;
                    }

                    // Parse seconds into mins and secs
                    mins = Math.floor(timeSecs / 60);
                    secs = timeSecs % 60;
                
                    var mins = vm.checkTime(mins);
                    var secs = vm.checkTime(secs);

                    // Display the time remaining in the element with id="output"
                    vm.output = "Time remaining: " + mins + ":" + secs;
                    timeSecs--;

                    // If the count down is finished, write expired in red
                    if (timeSecs < 0 && vm.repeat == 1) {
                        clearInterval(x);
                        vm.outstyle = "color: red;";
                        vm.output = "EXPIRED";
                        if (counter > 0) {
                            counter++;
                            vm.cnt = "Counter = " + counter;
                        }
                        //var done = new Audio('http://soundbible.com/mp3/Click On-SoundBible.com-1697535117.mp3')
                        vm.done.play()
                        vm.isRunning = false;
                        return;
                    }
                    // If repeat is selected, a counter appears with the current count
                    // and the timer is reset.
                    else if (timeSecs < 0 && vm.repeat > 1) {
                        counter++;
                        vm.cnt = "Counter = " + counter;
                        vm.ding.play()
                        timeSecs = vm.timeMins * 60;
                        vm.repeat--;
                    }
                }, 1000);
            }
        }
    }
</script>

<style scoped>
    .timer {
        display: flex;
        flex-flow: column nowrap;
        align-items: center;
        /* border: 1px solid black; */
        max-width: 800px;
        margin-bottom: 15px;
    }
    
    .inps {
        margin: 10px;
        padding: 10px;
        width: 200px;
        /* border: 5px solid gray; */
        font-weight: bold;
        text-align-last: justify;
    }

    button {
        margin: 10px;
        width: 100px;
    }

    .out {
        margin: 10px;
    }

    .outs {
        width: 300px;
        margin: 10px;
        text-align: center;
        /* border: 1px solid black; */
    }

    input {
        margin: 5px;
        width: 50px;
    }
</style>