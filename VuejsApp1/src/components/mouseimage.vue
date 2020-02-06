<template>
    <div>
        <div @mouseover ="hover=!hover" @mouseleave="hover=!hover">
            <img v-if="hover" :src="image1" alt="Pic of me"/>
            <img v-else :src="image2" alt="Pic of me and ella" />
        </div>
    </div>
</template>

<script>
    

    export default {
        name: 'mouseimage',
        data: function () {
            return {          
                image1: require('@/assets/Wyman Shoots.jpg'),
                image2: require('@/assets/Me and Ella.jpg'),
                hover: true,
            }
        },
    };
</script>

<style scoped>
    img {
        border: 1px solid black;
        height: 400px;
    }

    .imgdiv {
        height: 400px;
    }
</style>