<template>
    <v-app id="inspire">

        <v-app-bar app clipped-left>
            <v-toolbar-title class="green--text">NoteTaker</v-toolbar-title>
        </v-app-bar>

        <v-content>
 
            <div class="" style="width: 500px; margin: auto;">
                <div>
                    <span>Click a selection below</span>
                    <v-tabs color="green" v-model="tab" vertical>
                        <v-tab v-for="item in items" :key="item.tab">
                            {{item.tab}}
                        </v-tab>
                        <v-tabs-items v-model="tab">
                            <v-tab-item v-for="item in items" :key="item.tab">
                                <v-card flat>
                                    <v-card-text>
                                        {{item.content}}
                                    </v-card-text>
                                    <v-card-actions>
                                        <v-btn class="btn" color="green" small dark @click="makeReq">
                                            Submit
                                        </v-btn>
                                    </v-card-actions>
                                </v-card>
                            </v-tab-item>
                        </v-tabs-items>
                    </v-tabs>
                    <div class="selectWrap">
                        
                    </div>

                </div>
                <v-card
                    max-width="344"
                    class="mx-auto"
                >
                    <v-list-item>
                    <v-list-item-avatar color="grey"></v-list-item-avatar>
                    <v-list-item-content>
                        <v-list-item-title class="headline">Our Changing Planet</v-list-item-title>
                        <v-list-item-subtitle>by Kurt Wagner</v-list-item-subtitle>
                    </v-list-item-content>
                    </v-list-item>

                    <v-img
                    src="https://cdn.vuetifyjs.com/images/cards/mountain.jpg"
                    height="194"
                    ></v-img>

                    <v-card-text>
                    Visit ten places on our planet that are undergoing the biggest changes today.
                    </v-card-text>

                    <v-card-actions>
                    <v-btn
                        text
                        color="deep-purple accent-4"
                    >
                        Read
                    </v-btn>
                    <v-btn
                        text
                        color="deep-purple accent-4"
                    >
                        Bookmark
                    </v-btn>
                    <v-spacer></v-spacer>
                    <v-btn icon>
                        <v-icon>mdi-heart</v-icon>
                    </v-btn>
                    <v-btn icon>
                        <v-icon>mdi-share-variant</v-icon>
                    </v-btn>
                    </v-card-actions>
                </v-card>
            </div>

        </v-content>

        <v-footer app>
            <span>&copy; 2019 - Layout Components from Vuetify</span>
        </v-footer>
    </v-app>
</template>

<script>

    export default {
        props: {
            source: String,
        },
        data: () => ({

            tab: null,
            name: null,
            item_id: null,
            output: null,

            items: [
                { tab: 'INSERT', content: 'Insert a name for the field' },
                { tab: 'GET', content: 'Insert a name for the field' },
                { tab: 'DELETE', content: 'Insert a name for the field' },
                { tab: 'UPDATE', content: 'Insert a name for the field'},
            ],
         }),
        methods: {
            makeReq: function () {
                const url = 'https://5261puzqsb.execute-api.us-west-2.amazonaws.com/default';
                //const key = 'szqaVuropf37NRM8CgdhH3ekEynhYaEewYYz36Qb';

                var reqdata = {};

                reqdata["action"] = this.items[this.tab].tab;
                // reqdata["name"] = this.name;
                // reqdata["id"] = this.itemid;

                console.log(reqdata);

                const params = {
                    method: "POST",
                    body: JSON.stringify(reqdata)
                };
             
                fetch(url, params)
                    .then(data => {
                        return data.json();
                    })
                    .then(res => {
                        this.output = res;
                    })

                    .catch(error => this.output = error)
            }
        }
    }
</script>

<style scoped>
    .selectWrap {
        display: flex;
        justify-content: center;     
        margin: auto;
    }
    .btn {
        margin: 10px;
    }
    .tbl {
        text-align: center;
        margin: auto;
        padding: 10px;
        /* border: 5px soild red; */
    }
    .tbl th, .tbl td {
        padding: 10px 20px;
    }
    .names {
        text-align: left;
    }
</style>