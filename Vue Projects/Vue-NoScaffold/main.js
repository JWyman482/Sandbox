var app = new Vue({
    el: '#app',
    data: {
        product: 'socks',
        description: 'white socks',
        image: '../../../../../Pictures/Camera Roll/Me and Ella.jpg'
    }
});

let protoRabbit = {
    speak(line) {
        console.log(`The ${this.type} rabbit says '${line}'`);
    }
};

let killerRabbit = Object.create(protoRabbit);
killerRabbit.type = "killer";
killerRabbit.speak("Skreeee!!");

let testStr = "John";
let testObj = {};
// testObj[testStr];
// console.log(testObj).testStr;
console.log(testObj[testStr]);
console.log(testObj[testStr]==null);

