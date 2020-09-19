<template>
    <div>
        <div class = "img" @mouseover = "hover=!hover" @mouseleave = "hover=!hover">
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
                hover: false,
            }
        },
    };
</script>

<style scoped>
    img {
        height: 100%;
        width: 100%;
    }

    .imgdiv {
        height: 400px;
        border: 1px solid red;
        width: 715px;
    }

</style>