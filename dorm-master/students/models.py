from django.db import models
from django.db.models.signals import pre_save, post_save

from .utils import unique_slug_generator
from .validators import validate_section

# Create your models here.



class StudentInfo(models.Model):
	reg_no 		= models.IntegerField(null = True, blank = True)
	name	 	= models.CharField( max_length = 1000 ,null = True, blank = True)
	cgpa	 	= models.FloatField(null = True, blank = True)
	section 	= models.CharField(max_length = 100, null = True, blank = True, validators = [validate_section])
	course 		= models.CharField(max_length = 1000, null = True, blank = True)

	slug 		= models.SlugField(null = True, blank = True)
	date_added  = models.DateTimeField(auto_now_add = True, null = True, blank = True)
	last_updates = models.DateTimeField(auto_now = True, null = True, blank = True)


	def __str__(self):
		return f'{self.reg_no} - {self.name}'

	@property
	def title(self):
		return self.name
	
	




def student_info_pre_save(sender, instance, *args, **kwargs):
	if not instance.slug:
		instance.slug = unique_slug_generator(instance)


pre_save.connect(student_info_pre_save, sender = StudentInfo)
