#include <stdio.h>
//#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <xmlfile>\n", argv[0]);
        return 1;
    }

    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
    xmlNode *cur_node = NULL;

    doc = xmlReadFile(argv[1], NULL, 0);

    if (doc == NULL) {
        printf("Could not parse file %s\n", argv[1]);
        return 1;
    }

    root_element = xmlDocGetRootElement(doc);

    for (cur_node = root_element->children; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE &&
            xmlStrcmp(cur_node->name, (const xmlChar *)"book") == 0) {

            xmlNode *child = NULL;

            for (child = cur_node->children; child; child = child->next) {
                if (child->type == XML_ELEMENT_NODE &&
                    xmlStrcmp(child->name, (const xmlChar *)"title") == 0) {

                    xmlChar *title = xmlNodeGetContent(child);
                    printf("Book Title: %s\n", title);
                    xmlFree(title);
                }
            }
        }
    }

    xmlFreeDoc(doc);
    xmlCleanupParser();

    return 0;
}
