<template>
    <v-app id="inspire">


        <v-app-bar app
                   clipped-left>
       
            <v-toolbar-title class="green--text">NoteTaker</v-toolbar-title>
        </v-app-bar>

        <v-content>
 
            <div class="" style="width: 500px; margin: auto;">
                <div>
                    <v-tabs color="green"
                            v-model="tab"
                            vertical>
                        <v-tab v-for="item in items"
                               :key="item.tab">
                            {{item.tab}}
                        </v-tab>
                        <v-tabs-items v-model="tab">
                            <v-tab-item v-for="item in items"
                                        :key="item.tab">
                                <v-card flat>
                                    <v-card-text></v-card-text>
                                    <v-textarea :placeholder="item.content"
                                                v-model="name">

                                    </v-textarea>
                                </v-card>
                            </v-tab-item>
                        </v-tabs-items>
                    </v-tabs>
                </div>
                {{name}}
            </div>

        </v-content>

        <v-footer app>
            <span>&copy; 2019 - Layout Components from Vuetify</span>
        </v-footer>
    </v-app>
</template>

<script>

    //const url = 'https://5261puzqsb.execute-api.us-west-2.amazonaws.com/default';
    ////const key = 'szqaVuropf37NRM8CgdhH3ekEynhYaEewYYz36Qb';
    //const reqdata = {
    //    "action": "get"
    //};
    
    //const params = {
    //    method: "POST",
    //    body: JSON.stringify(reqdata)
    //};
    //const serverResponse = document.getElementById("serverResponse");


    //fetch(url, params)
    //    .then(data => {
    //        return data.json();
    //    })
    //    .then(res => {
    //        console.log(res)
    //        serverResponse.innerHTML = res;
    //    })

    //    .catch(error => console.log(error))

    export default {
        props: {
            source: String,
        },
        data: () => ({
            drawer: null,
            tab: null,
            name: null,
            id: null,
            item_id: null,
            items: [
                { tab: 'INSERT', content: 'Insert a name for the field' },
                { tab: 'GET', content: 'Insert a name for the field' },
                { tab: 'DELETE', content: 'Insert a name for the field' },
                { tab: 'UPDATE', content: 'Insert a name for the field'},
            ],
            reqMeths: [
                {
                    text: "INSERT",
                    value: "INSERT"
                },
                {
                    text: "GET",
                    value: "GET"
                },
                {
                    text: "UPDATE",
                    value: "UPDATE"
                },
                {
                    text: "DELETE",
                    value: "DELETE"
                },
            ],
        }),
        created() {
            //this.$vuetify.theme.dark = true
        },
    }
</script>

<style scoped>
    .selectWrap {
        justify-content: center;
        align-items: center;
        margin: auto;
        
        
    }
</style>