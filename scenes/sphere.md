scene->obj[0] = obj(SPHERE,							// type
				45.0,								// radius
				0.0,								// height
				vecp(50.0, 45.0, 50.0), 			// position
				vecp(0.0, 1.0, 0.0), 				// direction
				vecp(0.0, 0.0, 0.0),				// emission
				vecp(0.0, 0.0, 1.0),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0,									// Angle
				0,									// Cut direction
				0, 0, 0,							// Box rect
				DIFF);								// material

// Lumiere haute

scene->obj[1] = obj(BOX,							// type
				0.0,								// radius
				0.0,								// height
				vecp(0.0, 130.0, 0.0), 				// position
				vecp(0.0, 1.0, 0.0), 				// direction
				vecp(12.0, 12.0, 12.0),				// emission
				vecp(0.0, 0.0, 0.0),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0,									// Angle
				0,									// Cut direction
				100.0, 1.0, 100.0,					// Box rect
				DIFF);								// material

// Scenette

scene->obj[2] = obj(BOX,							// type
				0.0,								// radius
				0.0,								// height
				vecp(0.0, 0.0, 0.0), 				// position
				vecp(0.0, 1.0, 0.0), 				// direction
				vecp(0.0, 0.0, 0.0),				// emission
				vecp(0.5, 0.5, 0.5),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0,									// Angle
				0,									// Cut direction
				100.0, 1.0, 100.0,					// Box rect
				DIFF);								// material

// Lumiere gauche

scene->obj[3] = obj(BOX,							// type
				0.0,								// radius
				0.0,								// height
				vecp(-50.0, 0.0, 0.0), 				// position
				vecp(0.0, 1.0, 0.0), 				// direction
				vecp(12.0, 12.0, 12.0),				// emission
				vecp(0.0, 0.0, 0.0),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0,									// Angle
				0,									// Cut direction
				1.0, 100.0, 100.0,					// Box rect
				DIFF);								// material

// Lumiere camera

scene->obj[4] = obj(BOX,							// type
				0.0,								// radius
				0.0,								// height
				vecp(0.0, 0.0, 290.0), 				// position
				vecp(0.0, 1.0, 0.0), 				// direction
				vecp(5.0, 5.0, 5.0),				// emission
				vecp(0.0, 0.0, 0.0),				// color
				vecp(0.0, 0.0, 0.0),				// rotation
				0,									// Angle
				0,									// Cut direction
				100.0, 100.0, 1.0,					// Box rect
				DIFF);								// material
