<template>
    <div class = "taskcontainer">
        
        <div class = "addTask">
            <input id="myInput" class = "textInput" v-model="message" placeholder="Add tasks here">
            <button class="btn" id="myBtn" @click="newTask(message)" >➕</button>
            <button class="btn" @click="showTask = !showTask">✳</button>
            <button class="btn" @click="clearTasks">💥</button>
        </div>

        <Task 
            v-for="(task, index) in tasks" 
            :id="index+1" 
            :key="index"
            :text="task.text"
            :sounds="sounds"
            :showTask="showTask"
        />

    </div>
</template>

<script>
import Task from './Task.vue'

var tasks = []

var sounds = {
    'ClickOn': 'http://soundbible.com/mp3/Click On-SoundBible.com-1697535117.mp3',
    'ClickOff': 'http://soundbible.com/mp3/Button Click Off-SoundBible.com-1730098776.mp3',
}

export default {
    components: {
        Task
    },
    data() {
        return {
            tasks,
            message: "",
            sounds,
            showTask: true
        }
    },
    mounted: function() {
        // Get the input field
        var input = document.getElementById("myInput");

        // Execute a function when the user releases a key on the keyboard
        input.addEventListener("keyup", function(event) {
        // Number 13 is the "Enter" key on the keyboard
        if (event.keyCode === 13) {
            // Cancel the default action, if needed
            event.preventDefault();
            // Trigger the button element with a click
            document.getElementById("myBtn").click();
        }
        });
    },
    methods: {
        newTask(message) {
            this.tasks.push({id: tasks.length+1, text: message})
        },
        clearTasks() {
            this.tasks = [];
        }
    }
}
</script>

<style scoped>
.taskcontainer {
    display: flex;
    flex-flow: column nowrap;
    margin-bottom: 20px;
}

.textInput {
    padding: 10px;
    margin: 10px;
    border: 1px solid gray;
    
}

.textInput:hover {
    box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);
    
}

.btn {
    margin: 5px;
}
</style>