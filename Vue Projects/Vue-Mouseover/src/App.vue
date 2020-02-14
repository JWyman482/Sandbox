<template>
    <div id="app">
        <Home msg="Hello world!" />
        <Mouseimage></Mouseimage>
    </div>
</template>

<script>
    import Home from './components/Home.vue';
    import Mouseimage from './components/mouseimage.vue';

    export default {
        name: 'app',
        components: {
            Home,
            Mouseimage
        }
    };
</script>

<style>
</style>

