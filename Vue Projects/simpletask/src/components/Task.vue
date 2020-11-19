<template>
<div class="task" :class = "{done : isDone}">
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
        'sounds'
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
        /* justify-content: space-between; */
        margin: 8px;
        padding: 2px;
        border: 1px solid lightgray;
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
        /* height: 100%; */
        /* border: 1px solid red; */
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