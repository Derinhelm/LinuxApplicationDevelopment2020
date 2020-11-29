#include <glib.h>
#include <stdio.h>

#define BUF_SIZE 81

gint
comp(GSList *a, GSList *b) {
    gint a1 = *(int *)g_slist_nth_data(a, 1);  
    gint b1 = *(int *)g_slist_nth_data(b, 1);
    if (a1 > b1)
        return -1;
    else if (a1 == b1)
        return 0;
    else 
        return 1;
}

void str_parse(GHashTable *hash, char * s) {
    gchar *word, *word_copy;
    gchar ** s_split = g_strsplit_set(s, "\n ", -1);
    gint ind;
    gpointer hash_pointer;
    for (ind = 0; ind < g_strv_length(s_split); ind++) {
        word = s_split[ind];
        hash_pointer = g_hash_table_lookup(hash, word);
        if (hash_pointer) {
            (*(gint *) hash_pointer)++;
        } else {
            gint* first_occur = g_new(gint, 1);
            *first_occur = 1;
            word_copy = g_strdup(word);
            g_hash_table_insert(hash, word_copy, first_occur);
        }
    }
    g_strfreev(s_split);
    return;
}

int main(int argc, char** argv) {
    char *buf = malloc(BUF_SIZE);
    GHashTable * hash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    while (fgets(buf, BUF_SIZE - 1, stdin) != NULL) {
        str_parse(hash, buf); 
    }
    free(buf);
    GSList *list = NULL, *tuple, *item;
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init (&iter, hash);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
	if (g_strcmp0(key, "") != 0) {
            tuple = NULL;
            tuple = g_slist_append(tuple, key);
            tuple = g_slist_append(tuple, value);
            list = g_slist_append(list, tuple);
        }
    }
    list = g_slist_sort(list, (GCompareFunc)comp);
    for(item = list; item; item = item->next) {
        printf("%s %d\n", (char *)g_slist_nth_data(item->data, 0), *(int *)g_slist_nth_data(item->data, 1));
    }
    g_hash_table_destroy(hash);
    for(item = list; item; item = item->next) {
        g_slist_free(item->data);
    }
    g_slist_free(list);
    return 0;
}
