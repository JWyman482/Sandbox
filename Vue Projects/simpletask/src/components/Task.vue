<template>
<div class="task" :class = "{done : isDone}" v-if="!isDone || (showTask && isDone)">
    <div class = "btn"><input type="checkbox" v-model="isDone" v-on:change="playAudio(sounds)" /></div>
    <div class = "taskLeft">
        <div class = "label"><strong>{{id}}</strong></div>
        <div class = "text">{{text}}</div>
    </div>
</div>

</template>

<script>
export default {
    props: [
        'id',
        'text',
        'sounds',
        'showTask'
    ],
    data() {
        return {
            isDone: false,
        }
    },
    methods: {
        playAudio(sounds) {
            var clickOn = new Audio(sounds['ClickOn']);
            var clickOff = new Audio(sounds['ClickOff']);

            if (this.isDone) {
                clickOn.play();
            }
            else clickOff.play();
        }
    }
}
</script>

<style scoped>
    .task {
        display: flex;
        flex-flow: row nowrap;
        margin: 8px;
        padding: 2px;
        border: 1px solid lightgray;
    }

    .task:hover {
        box-shadow: 0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19);
    }

    .taskLeft {
        display: flex;
        flex-wrap: nowrap;
        text-align: left;
    }

    .label {
        font-weight: bold;
        margin: 5px;
        margin-left: 10px;
    }

    .text {
        margin: 5px;
    }

    .btn {
        align-self: center;
    }

    button {
        height: 15px;
        vertical-align: middle;
        margin-top: 5px;
    }

    .done {
        text-decoration: line-through;
        order: 99;
    }
</style>