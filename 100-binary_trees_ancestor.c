#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t c = 0;
	binary_tree_t *tmp;

	if (!tree)
		return (0);
	tmp = (binary_tree_t *)tree;
	while (tmp->parent)
	{
		c++;
		tmp = tmp->parent;
	}
	return (c);
}

/**
 * binary_tree_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t d1, d2, i;
	binary_tree_t *node1, *node2;

	if (!first || !second)
		return (NULL);
	d1 = binary_tree_depth(first);
	d2 = binary_tree_depth(second);
	node1 = (binary_tree_t *)first;
	node2 = (binary_tree_t *)second;
	i = 0;
	if (d1 > d2)
	{
		while (d1 - d2 - i)
		{
			node1 = node1->parent;
			i++;
		}
	}
	else if (d2 > d1)
	{
		while (d2 - d1 - i)
		{
			node2 = node2->parent;
			i++;
		}
	}
	while (node1)
	{
		if (node1 == node2)
			return (node1);
	node1 = node1->parent;
	node2 = node2->parent;
	}
	return (NULL);
}
