<template>
    <div class = "taskcontainer">
        <h1>Task List</h1>
        <Task 
            v-for="(task, index) in tasks" 
            :id="index+1" 
            :key="index"
            :text="task.text"
            :sounds="sounds"
        />
        <div class = "addTask">
            <input class = "textInput" v-model="message" placeholder="Text here">
            <button @click="newTask(message)">➕</button>
        </div>
    </div>
</template>

<script>
import Task from './Task.vue'

var tasks = []

var sounds = {
    'ClickOn': 'http://soundbible.com/mp3/Click On-SoundBible.com-1697535117.mp3',
    'ClickOff': 'http://soundbible.com/mp3/Button Click Off-SoundBible.com-1730098776.mp3',
    'Success': './assets/success-jingle.wav'
}

export default {
    components: {
        Task
    },
    data() {
        return {
            tasks,
            message: "",
            sounds
        }
    },
    methods: {
        newTask(message) {
            this.tasks.push({id: tasks.length+1, text: message})
        }
    }
}
</script>

<style scoped>
.taskcontainer {
    display: flex;
    flex-flow: column nowrap;
    max-width: 800px;
    margin: 0 auto;
}

.textInput {
    padding: 10px;
    margin: 10px;
    border: 2px solid green;
}

.textInput:hover {
    box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);
    
}
</style>